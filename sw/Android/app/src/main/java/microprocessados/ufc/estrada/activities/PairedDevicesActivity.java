package microprocessados.ufc.estrada.activities;

import android.bluetooth.BluetoothAdapter;
import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.Toast;

import microprocessados.ufc.estrada.CustomAdapter;
import microprocessados.ufc.estrada.R;
import microprocessados.ufc.estrada.controllers.BluetoothController;

public class PairedDevicesActivity extends AppCompatActivity {

    private BluetoothController bluetoothController;
    private ListView devicesList;
    private Handler connectHandler;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_paired_devices);
    }

    private void setBluetooth() {
        try {
            devicesList = (ListView) findViewById(R.id.devicesLists);
            if(bluetoothController==null)
                bluetoothController = new BluetoothController(connectHandler);
            final CustomAdapter adapter = new CustomAdapter(this, android.R.layout.simple_list_item_1, bluetoothController.getPairedDevices());
            devicesList.setAdapter(adapter);
            devicesList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                @Override
                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                    Intent intent = new Intent(getApplicationContext(),BotaoInicialActivity.class);
                    intent.putExtra("Device", adapter.getItem(position));
                    startActivity(intent);
                }
            });
        }catch (BluetoothController.NoBluetoothFoundException e1){
            Toast.makeText(this,"O dispositivo não possui Bluetooth. Seu Pobre!",Toast.LENGTH_SHORT).show();
        }catch (BluetoothController.BluetoothDisabledException e2){
            Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBtIntent, 1);
        }
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d("RESTART","RESTARTANDO");
    }

    @Override
    protected void onResume() {
        super.onResume();
        setBluetooth();
        Log.d("RESUMO","RESUMINDO");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.d("PAUSE","PAUSANDO");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        bluetoothController.disconnect();
    }

}

