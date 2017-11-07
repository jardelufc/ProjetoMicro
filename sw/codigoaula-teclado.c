#include"stm32f10x.h"
#include"stm32f10x_gpio.h" //biblioteca para controle de gpio
#include"stm32f10x_rcc.h" //biblioteca para controle de reset e clock

GPIO_InitTypeDef GPIO_InitStruct;

int main(void)
{
	int k, t;
	//habilita clock para gpioA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	//linhas
	//linha1
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//linha2
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//linha3
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//linha4
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//colunas
	//coluna 1
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//coluna 2
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//coluna 3
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//led
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	while(1)
	{
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		//escanear coluna 1
		
			GPIO_ResetBits (GPIOA, GPIO_Pin_4);
			GPIO_SetBits (GPIOA, GPIO_Pin_5);
			GPIO_SetBits (GPIOA, GPIO_Pin_6);
			for(k=5;k>0;k--); //delay
			//ler linhas
			if (!(GPIO_ReadInputData(GPIOA) & GPIO_Pin_0)){
							for(t=1;t>0;t--){
							GPIO_ResetBits(GPIOC, GPIO_Pin_13);
							for(k=1440000;k>0;k--);
							GPIO_SetBits(GPIOC, GPIO_Pin_13);
							for(k=1440000;k>0;k--);};}
			if (!(GPIO_ReadInputData(GPIOA) & GPIO_Pin_1)){
							for(t=4;t>0;t--){
							GPIO_ResetBits(GPIOC, GPIO_Pin_13);
							for(k=1440000;k>0;k--);
							GPIO_SetBits(GPIOC, GPIO_Pin_13);
							for(k=1440000;k>0;k--);};}
			if (!(GPIO_ReadInputData(GPIOA) & GPIO_Pin_2)){
							for(t=7;t>0;t--){
							GPIO_ResetBits(GPIOC, GPIO_Pin_13);
							for(k=1440000;k>0;k--);
							GPIO_SetBits(GPIOC, GPIO_Pin_13);
							for(k=1440000;k>0;k--);};}
			if (!(GPIO_ReadInputData(GPIOA) & GPIO_Pin_3)){
							for(t=1;t>0;t--){
							GPIO_ResetBits(GPIOC, GPIO_Pin_13);
							for(k=14400000;k>0;k--);
							GPIO_SetBits(GPIOC, GPIO_Pin_13);
							for(k=14400000;k>0;k--);};}
	}
}
