// Fill out your copyright notice in the Description page of Project Settings.

#include "RWTxtFile.h"

/*
bool URWTxtFile::LoadTxt(FString FileNameA, FString& SaveTextA)
{
	enum { FILEREAD_AllowWrite = 0x04};
	//AllowWrite = 0x04;
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA), EFileRead::FILEREAD_AllowWrite);
}

bool URWTxtFile::SaveTxt(FString SaveTextB, FString FileNameB)
{
	enum { FILEWRITE_Append = 0x08};
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB), FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

bool URWTxtFile::SaveArray(TArray<uint8> Array, FString FileNameC)
{
	enum { FILEWRITE_Append = 0x08};
	return FFileHelper::SaveArrayToFile(Array, *(FPaths::GameDir() + FileNameC), &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

bool URWTxtFile::LoadArray(FString& FilenameD,TArray<uint8> ArrayB)
{
	return FFileHelper::LoadFileToArray(ArrayB, *(FPaths::GameDir() + FilenameD));
}
*/
FVector CarregarLista(FString NomeArquivo, list<float>*Lista, bool&Carregado) {
	float numero;
	float numero1;
	float numero2;
	float numero3;
	FVector Vetor = FVector(0.0f, 0.0f, 0.0f);
	FString arquivo = "D:\\Vinicius Oliveira\\Git\\Test_Master\\Txt-master\\" + NomeArquivo + ".txt";
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	if(Carregado == false){
		ifstream input;
		input.open(arquivo2);
		while (input.good()) {
			input >> numero;
			input >> numero;
			for(int i = 0; i < 6;i++) {
				input >> numero;
				if (input.good()) {
					Lista->push_back(numero);
				}
			}
		}
		input.close();
		Carregado = true;
	}
	numero1 = Lista->front();
	Lista->pop_front();
	numero2 = Lista->front();
	Lista->pop_front();
	numero3 = Lista->front();
	Lista->pop_front();
	Vetor.X = numero1;
	Vetor.Y = numero2;
	Vetor.Z = numero3;
	return Vetor;
}

void URWTxtFile::Carregar(FString NomeArquivo, bool&Carregado, FVector&Vet){
}

void URWTxtFile::SetTrajetoria(AActor *SelectActor, FString NomeDoArquivo,int Num) {
	float numero = 0.0;
	float numero1 = 0.0;
	float numero2 = 0.0;
	float numero3 = 0.0;
	bool bSweep = false;
	bool Check = false;
	FRotator Rot = FRotator(0.0f, 0.0f, 0.0f);
	FVector Trans = FVector(100.0f, 100.0f, 100.0f);
	FVector Scale = FVector(1.0f, 1.0f, 1.0f);
	ETeleportType Teleport = ETeleportType::None;
	FTransform Traj = FTransform( Rot, Trans, Scale);
	FHitResult* OutSweepHit = nullptr;
	Check = SelectActor->SetActorTransform(Traj, bSweep, OutSweepHit, Teleport);
	FString arquivo = "D:\\Vinicius Oliveira\\Git\\Test_Master\\Txt-master\\" + NomeDoArquivo + ".txt";
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	ifstream input;
	input.open(arquivo2);
	//for (int i = 1; i < Num; i++) {
		//for (int j = 0; j < 8; j++)
			//input >> numero;
	//}
	while (input.good()) {
		//for (int i = 0; i < 20000;i++) //Retardos
			//numero = numero + 1;
		//}
		input >> numero;
		input >> numero;
		input >> numero1;
		input >> numero2;
		input >> numero3;
		Rot.Pitch = numero1;
		Rot.Roll = numero2;
		Rot.Yaw = numero3;
		input >> numero1;
		input >> numero2;
		input >> numero3;
		Trans.X = numero1;
		Trans.Y = numero2;
		Trans.Z = numero3;
		Traj = FTransform(Rot, Trans, Scale);
		Check = SelectActor->SetActorTransform(Traj, bSweep, OutSweepHit, Teleport);
	}
	input.close();
	Trans.X = 100;
	Trans.Y = 100;
	Trans.Z = 100;
	Traj = FTransform(Rot, Trans, Scale);
	Check = SelectActor->SetActorTransform(Traj, bSweep, OutSweepHit, Teleport);
	//for (int i = 0; i < 1000000000;i++) {  //Retardos
		//numero = numero + 1;
	//}
	input.open(arquivo2);
	while (input.good()) {
		//for (int i = 0; i < 20000;i++) {  //Retardos
			//numero = numero + 1;
		//}
		input >> numero;
		input >> numero;
		input >> numero1;
		input >> numero2;
		input >> numero3;
		Rot.Pitch = numero1;
		Rot.Roll = numero2;
		Rot.Yaw = numero3;
		input >> numero1;
		input >> numero2;
		input >> numero3;
		Trans.X = numero1;
		Trans.Y = numero2;
		Trans.Z = numero3;
		Traj = FTransform(Rot, Trans, Scale);
		Check = SelectActor->SetActorTransform(Traj, bSweep, OutSweepHit, Teleport);
	}
	input.close();
	Trans.X = 180;
	Trans.Y = 180;
	Trans.Z = 180;
	Traj = FTransform(Rot, Trans, Scale);
	Check = SelectActor->SetActorTransform(Traj, bSweep, OutSweepHit, Teleport);
	//delete Traj;
	//Só para lembra como chama a função SetActorTransform
	//Check = SelectActor -> SetActorTransform(Traj, bSweep, OutSweepHit, Teleport);
	
}

void URWTxtFile::NumCoo(FString FileNameG, bool&Carregado, int&num) {
	float numero;
	int num2 = 0;
	FString arquivo = "D:\\Vinicius Oliveira\\Git\\Test_Master\\Txt-master\\" + FileNameG + ".txt";
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	ifstream input;
	input.open(arquivo2);
	while (input.good()) {
		for (int i = 0; i < 8; i++)
			input >> numero;
		if(input.good())
			num2 = num2 + 1;
	}
	input.close();
	num = num2;
	Carregado = true;
}

void URWTxtFile::LerCoo(FString FileNameF,int Num, FVector&VetorRot, FVector&VetorTran) {
	float numero;
	float numero1;
	float numero2;
	float numero3;
	numero = 0.0;
	numero1 = 0.0;
	numero2 = 0.0;
	numero3 = 0.0;
	FVector VetorR = FVector(0.0f, 0.0f, 0.0f);
	FVector VetorT = FVector(0.0f, 0.0f, 0.0f);
	FString arquivo = "D:\\Vinicius Oliveira\\Git\\Test_Master\\Txt-master\\" + FileNameF + ".txt";
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	ifstream input;
	input.open(arquivo2);
	for (int i = 1; i < Num; i++) {
		for (int j = 0; j < 8; j++)
			input >> numero;
	}
	input >> numero;
	input >> numero;
	//Coordenada desejada  Rot
	input >> numero1;
	input >> numero2;
	input >> numero3;
	VetorR.X = numero1;
	VetorR.Y = numero2;
	VetorR.Z = numero3;
	VetorRot = VetorR;
	//Coordenada desejada Tran
	input >> numero1;
	input >> numero2;
	input >> numero3;
	VetorT.X = numero1;
	VetorT.Y = numero2;
	VetorT.Z = numero3;
	VetorTran = VetorT;
	input.close();
}

void URWTxtFile::LerTexto(FString FileNameE,  FVector&VetorLegalR, FVector&VetorLegalT)
{
	//Funciona
	//IMPORTANTE: TEM QUE DEIXAR UM ESPAÇO NO FINAL DO ARQUIVO, CASO CONTRÁRIO O PROGRAMA
	//PERDE A ÚLTIMA COORDENADA.
	using namespace std;
	list<float> *lista = new list <float>();
	float numero;
	float numerof;
	float numero1;
	float numero2;
	float numero3;
	//float virg;
	FString arquivo;
	//bool terminou;
	int erro = 0;
	int tamanho = 0;
	numero = 0.0;
	numero1 = 0.0;
	numero2 = 0.0;
	numero3 = 0.0;
	numerof = 0.0;
	arquivo = "D:\\Vinicius Oliveira\\Git\\Test_Master\\Txt-master\\" + FileNameE + ".txt";
	//Converte FString para string
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	FVector VetorT = FVector(0.0f, 0.0f, 0.0f);
	FVector VetorR = FVector(0.0f, 0.0f, 0.0f);
	ifstream input;
	//Funciona
	//input.open("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt");
	input.open(arquivo2);
	//Jogar lixo no lixo
	input >> numero;                        //1
	//input >> virg;                          //2
	input >> numero;                        //3
	//input >> virg;                          //4
	// Vetor R
	// RX
	input >> numero;
	//if (input.good()) {
		numero1 = numero;                   //5
	//}
	//else erro = 1;
	//input >> virg;                          //6
	//
	// RY
	input >> numero;
	//if (input.good()) {
		numero2 = numero;                   //7
	//}
	//else erro = 1;
	//input >> virg;                          //8
	//
	// RZ
	input >> numero;
	//if (input.good()) {
		numero3 = numero;                   //9
	//}
	//else erro = 1;
	//input >> virg;                          //10
	//
	if (erro == 0) {
		VetorR.X = numero1;//5
		VetorR.Y = numero2;//7
		VetorR.Z = numero3;//9
	}
	VetorLegalR = VetorR;
	// Vetor R
	// X 
	input >> numero;
	//if (input.good()) {
		numero1 = numero;                   //11
	//}
	//else erro = 1;
	//input >> virg;                          //12
	//
	// Y 
	input >> numero;
	//if (input.good()) {
		numero2 = numero;                   //13
	//}
	//else erro = 1;
	//input >> virg;                          //14
	//
	// Z 
	input >> numero;
	//if (input.good()) {
		numero3 = numero;                   //15
	//}
	//else erro = 1;
	//input >> virg;
	//
	if (erro == 0) {
		VetorT.X = numero1;
		VetorT.Y = numero2;
		VetorT.Z = numero3;
	}
	VetorLegalT = VetorT;
	
	while (input.good()) {
		input >> numerof;
		if (input.good()) {
			lista->push_back(numerof);
		}
	}
	input.close();
	
	ofstream output;
	output.open(arquivo2);
	for (tamanho = lista->size(); tamanho > 0; tamanho--) {
		output << lista->front()<<" ";
		lista->pop_front();
	}
	output.close();
	
	//Alterado
	/*
	if (numero1 == 0 && numero2 == 0 && numero3 == 0) {
		terminou = true;
	}
	else terminou = false;
	return terminou;
	*/
	//input.close();
	//Escreve Arquivo
	/*
	ofstream output;
	output.open("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt",ios_base::app);
	output << 123.1 << " " << 124.2 << " " << 125.3<<" ";
	output.close();
	*/
	//Le Arquivo
	/*
	ifstream input;
	input.open ("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt");
	input >> numero;
	input >> numero2;
	input >> numero3;
	Vetor.X = numero;
	Vetor.Y = numero2;
	Vetor.Z = numero3;
	VetorLegal = Vetor;
	input.close();
	*/
	//Acrescentar Vetor, Carregar o texto inteiro
}

FVector URWTxtFile::EscreverTexto(FString FileNameD, FVector Lugar)
{
	using namespace std;
	float numero1;
	float numero2;
	float numero3;
	FString arquivo;
	numero1 = Lugar.X;
	numero2 = Lugar.Y;
	numero3 = Lugar.Z;
	arquivo = "D:\\Vinicius Oliveira\\Git\\Test_Master\\Txt-master" + FileNameD + ".txt";
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	ofstream output;
	output.open(arquivo2, ios_base::app);
	output << numero1 << " ";
	output << numero2 << " ";
	output << numero3 << " ";
	return Lugar;
}