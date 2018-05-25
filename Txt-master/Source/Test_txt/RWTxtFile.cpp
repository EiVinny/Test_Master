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

void URWTxtFile::LerTexto(FString FileNameE,  FVector&VetorLegal)
{
	//Funciona
	//IMPORTANTE: TEM QUE DEIXAR UM ESPAÇO NO FINAL DO ARQUIVO, CASO CONTRÁRIO O PROGRAMA
	//PERDE A ÚLTIMA COORDENADA.
	using namespace std;
	list<float> *lista = new list <float>();
	float numero;
	float numero1;
	float numero2;
	float numero3;
	FString arquivo;
	//bool terminou;
	int erro = 0;
	int tamanho = 0;
	numero = 0.0;
	numero1 = 0.0;
	numero2 = 0.0;
	numero3 = 0.0;
	arquivo = "D:\\Vinicius Oliveira\\Txt-master\\Txt-master" + FileNameE + ".txt";
	//Converte FString para string
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	FVector Vetor = FVector(0.0f, 0.0f, 0.0f);
	ifstream input;
	//Funciona
	//input.open("C:\\Users\\USP\\Documents\\GitHub\\Txt\\Location.txt");
	input.open(arquivo2);
	input >> numero;
	if (input.good()) {
		numero1 = numero;
	}
	else erro = 1;
	input >> numero;
	if (input.good()) {
		numero2 = numero;
	}
	else erro = 1;
	input >> numero;
	if (input.good()) {
		numero3 = numero;
	}
	else erro = 1;
	if (erro == 0) {
		Vetor.X = numero1;
		Vetor.Y = numero2;
		Vetor.Z = numero3;
	}
	VetorLegal = Vetor;
	while (input.good()) {
		input >> numero;
		if (input.good()) {
			lista->push_back(numero);
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
	arquivo = "D:\\Vinicius Oliveira\\Txt-master\\Txt-master" + FileNameD + ".txt";
	string arquivo2 = string(TCHAR_TO_UTF8(*arquivo));
	UE_LOG(LogTemp, Warning, TEXT("JSON %s"), *FString(arquivo2.c_str()));
	ofstream output;
	output.open(arquivo2, ios_base::app);
	output << numero1 << " ";
	output << numero2 << " ";
	output << numero3 << " ";
	return Lugar;
}