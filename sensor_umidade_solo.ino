#define sensor A0                     		//Define nome da variavel sensor associada ao pino A0
#define LED_VD 2                      		//Define nome da variavel LEDVD associada ao pino 2
#define LED_AM 3                      		//Define nome da variavel LEDAM associada ao pino 3
#define LED_VM 4                      		//Define nome da variavel LEDVM associada ao pino 4

void setup()                          		//Inicia a função setup (configuração)
	{                                 		//Abertura da função setup (configuração)
  	Serial.begin(9600);                     // Inicializa o monitor serial e define a taxa de transmissão de dados
  	pinMode(sensor, INPUT);           		//Define modo de operação do pino associado a sensor como entrada
  	pinMode(LED_VD, OUTPUT);          		//Define modo de operação do pino associado a LEDVD como saída
  	pinMode(LED_AM, OUTPUT);          		//Define modo de operação do pino associado a LEDAM como saída
    pinMode(LED_VM, OUTPUT);          		//Define modo de operação do pino associado a LEDVM como saída
	}                                 		//Fechamento da função setup (configuração)
 
void loop()                           		//Inicia a função loop (laço de repetição)
	{                                 		//Abertura da função loop (laço de repetição)
  	int sinal = analogRead(sensor);   		//Efetua leitura analógica da variavel sensor e armazena na variavel sinal do tipo int   
  	Serial.print("Sinal: ");                //Imprime no monitor serial o texto entre aspas duplas
  	Serial.print(sinal);                    //Imprime no monitor serial o valor da variavel LDR e pula linha

  	if (sinal >= 0 && sinal < 350)  		//Compara SE sinal atende a duas condições simultaneamente
  	{                        		        //Abertura da estrutura if (condicional)
    Serial.println(" Status: Solo seco");  //Imprime no monitor serial o texto entre aspas duplas 
    apagar();                               //Chama a função apagar para que apague todos os LEDs 
    digitalWrite(LED_VM, HIGH);             //Coloca a variável digital LEDAM em nível lógico alto
  	}                                       //Fechamento da estrutura if (condicional)
 
  	if (sinal >= 350 && sinal < 750)        //Compara SE sinal atende a duas condições simultaneamente
  	{                                       //Abertura da estrutura if (condicional)
    Serial.println(" Status: Umidade ok");  //Imprime no monitor serial o texto entre aspas duplas
    apagar();                               //Chama a função apagar para que apague todos os LEDs 
    digitalWrite(LED_VD, HIGH);             //Coloca a variável digital LEDVD em nível lógico alto
  	}                                       //Fechamento da estrutura if (condicional)
 
  	if (sinal >= 750 && sinal < 1023)       //Compara SE sinal atende a duas condições simultaneamente
  	{                                       //Abertura da estrutura if (condicional)
    Serial.println(" Status: Solo umido");   //Imprime no monitor serial o texto entre aspas duplas 
    apagar();                               //Chama a função apagar para que apague todos os LEDs 
    digitalWrite(LED_AM, HIGH);             //Coloca a variável digital LEDVM em nível lógico alto
  	}                                       //Fechamento da estrutura if (condicional)
  	delay(1000);                      		//Implementa atraso em ms
	}                                 		//Fechamento da função loop (laço de repetição)
 
void apagar()                         		//Cria e inicia a função apagar que não retorna nenhum dado
  	{                                 		//Abertura da função apagar 
  	digitalWrite(LED_VM, LOW);        		//Coloca a variável digital LEDVM em nível lógico alto
  	digitalWrite(LED_VD, LOW);        		//Coloca a variável digital LEDVD em nível lógico alto
  	digitalWrite(LED_AM, LOW);        		//Coloca a variável digital LEDAM em nível lógico alto
  	}                                 		//Fechamento da função apagar
