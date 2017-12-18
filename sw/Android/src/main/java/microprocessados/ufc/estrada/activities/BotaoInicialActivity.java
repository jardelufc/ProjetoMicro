package microprocessados.ufc.estrada.activities;

import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import microprocessados.ufc.estrada.R;

public class BotaoInicialActivity extends AppCompatActivity {

    private Button botao1;
    private Button botao2;
    private Button botao3;
    private BluetoothDevice device;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_botao_inicial);
        device = (BluetoothDevice) getIntent().getParcelableExtra("Device");
        botao1 = (Button) findViewById(R.id.botao1);
        botao1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(),TrafegoActivity.class);
                intent.putExtra("Device",device);
                startActivity(intent);
            }
        });
        botao2 = (Button) findViewById(R.id.botao2);
        botao2.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(),StatusPosteActivity.class);
                intent.putExtra("Device",device);
                startActivity(intent);
            }
        });
        botao3 = (Button) findViewById(R.id.botao3);
        botao3.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(),MainScreenActivity.class);
                intent.putExtra("Device",device);
                startActivity(intent);
            }
        });
    }
}
