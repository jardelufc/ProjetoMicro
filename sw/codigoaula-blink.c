While (1) {
      for(i=0;i<64;i++) {
              GPIOA->ODR=SineTable64[i];
        HAL_Delay(1);
}
}
HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
HAL_Delay(500);
