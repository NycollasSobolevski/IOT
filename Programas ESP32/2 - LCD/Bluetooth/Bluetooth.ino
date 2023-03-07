#define LED 13

void setup() (
  Serial .begin(115200);
  dht.begin();
  pinMode(LED, OUTPUT);
  // Create the BLE Device
  BLEDevice::init("MINHA-ESP"); // nome do dispositivo bluetooth
  // Cria o BLE Server
  BLEServer *server = BLEDevice::createServer(); //cria um BLE server
  server->setCallbacks(new ServerCallbacks()); //seta o callback do server
  // Cria o BLE Service
  BLEService *service = server->createService(SERVICE UUID);
  // Cria uma BLE Characteristic para envio de dados
  characteristicTX = service->createCharacteristic(
  CHARACTERISTIC UUID TX,
  BLECharacteristic: : PROPERTY NOTIFY
  
  )
  characteristicTX->addDescriptor (new BLE2902());
  // Cria uma BLE Characteristic para recebimento de dados
  BLECharacteristic *characteristic = service->createCharacteristic(
  
  CHARACTERISTIC UUID RX,
  26 BLECharacteristic::PROPERTY_WRITE
  );
  characteristic->setCallbacks(new CharacteristicCallbacks());
  // Start the service
  service->start();
  // Start advertising (ESP fica visível para outros dispositivos)
  server->getAdvertising()->start();
  Serial.println("Waiting a client connection to notify...");
}


void loop() {
  // put your main code here, to run repeatedly:

}
