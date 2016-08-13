// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectileMaster.generated.h"

UCLASS()
class ETHEREAL_API AProjectileMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileMaster();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
