// Fill out your copyright notice in the Description page of Project Settings.

#include "BuilderEPAleatoria.h"
#include "EsrtucturaPlataformas.h"
#include "FabricaPlataformas.h"
#include "Plataforma.h"
#include "PlataformaAerea.h"

// Sets default values
ABuilderEPAleatoria::ABuilderEPAleatoria()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	estructuraPlataformas = nullptr;

}
// Called when the game starts or when spawned
void ABuilderEPAleatoria::BeginPlay()
{
	Super::BeginPlay();

}
void ABuilderEPAleatoria::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilderEPAleatoria::construirEstructuraPlataforma()
{
	UWorld* World = GetWorld();
	if (World)
	{
		estructuraPlataformas = World->SpawnActor<AEsrtucturaPlataformas>(AEsrtucturaPlataformas::StaticClass());
	}
}

void ABuilderEPAleatoria::ConstruirEstructuraPlataformaaAereas()
{
	if (!estructuraPlataformas) return;
	UWorld* World = GetWorld();
	if (!World) return;

	AFabricaPlataformas* Fabrica = World->SpawnActor<AFabricaPlataformas>(AFabricaPlataformas::StaticClass());
	if (Fabrica)
	{
		FVector Loc = FVector(-300.0f, 0.0f, 400.0f);
		APlataforma* CompAereo = Fabrica->CrearPlataforma("Area", Loc, FRotator::ZeroRotator);
			if (CompAereo)
			{
				// Opcional: si la estructura tiene un arreglo para aereas
				estructuraPlataformas->aPlataformasAereas.Add(Cast<APlataformaAerea>(CompAereo));
			}
	}
}

void ABuilderEPAleatoria::ConstruirEstructuraPlataformaaTerrestres()
{
	if (!estructuraPlataformas) return;
	UWorld* World = GetWorld();
	if (!World) return;

	AFabricaPlataformas* Fabrica = World->SpawnActor<AFabricaPlataformas>(AFabricaPlataformas::StaticClass());
	if (Fabrica)
	{
		FVector Loc = FVector(0.0f, 0.0f, 100.0f);
		Fabrica->CrearPlataforma("Terrestre", Loc, FRotator::ZeroRotator);
	}
}

void ABuilderEPAleatoria::ConstruirEstructuraPlataformaaSubterraneas()
{
}

void ABuilderEPAleatoria::ConstruirEstructuraPlataformaaAcuaticas()
{
	if (!estructuraPlataformas) return;
	UWorld* World = GetWorld();
	if (!World) return;

	AFabricaPlataformas* Fabrica = World->SpawnActor<AFabricaPlataformas>(AFabricaPlataformas::StaticClass());
	if (Fabrica)
	{
		FVector Loc = FVector(300.0f, 0.0f, -100.0f);
		Fabrica->CrearPlataforma("Acuatica", Loc, FRotator::ZeroRotator);
	}
}

AEsrtucturaPlataformas* ABuilderEPAleatoria::GetEstructuraPlataformas()
{
	return estructuraPlataformas;
}


