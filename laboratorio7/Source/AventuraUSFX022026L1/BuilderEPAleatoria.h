// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderEstructuraPlataforma.h"
#include "EsrtucturaPlataformas.h" // <-- Incluir la cabecera directamente resuelve el error de UHT
#include "BuilderEPAleatoria.generated.h"

UCLASS()
class AVENTURAUSFX022026L1_API ABuilderEPAleatoria : public AActor, public IBuilderEstructuraPlataforma
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuilderEPAleatoria();

	virtual void ConstruirEstructuraPlataformaaAereas() override;
	virtual void ConstruirEstructuraPlataformaaTerrestres() override;
	virtual void ConstruirEstructuraPlataformaaSubterraneas() override;
	virtual void ConstruirEstructuraPlataformaaAcuaticas() override;
	virtual void construirEstructuraPlataforma() override;

	// Producto complejo que se está construyendo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Builder")
		AEsrtucturaPlataformas* estructuraPlataformas;

	AEsrtucturaPlataformas* GetEstructuraPlataformas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
