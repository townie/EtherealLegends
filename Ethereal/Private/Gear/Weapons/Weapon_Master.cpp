// © 2014 - 2016 Soverance Studios
// www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "Weapon_Master.h"

AWeapon_Master::AWeapon_Master(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Asset, Reference Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));

	// Set Default Objects
	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Create
	WeaponSkeletalMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Weapon Skeletal Mesh"));
	WeaponStaticMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Weapon Static Mesh"));
	WeaponOffhandMesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Weapon Offhand Mesh"));

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponSkeletalMesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
	WeaponSkeletalMesh->SetVisibility(false);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	WeaponStaticMesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
	WeaponStaticMesh->SetVisibility(false);
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);
	WeaponOffhandMesh->AttachToComponent(Root, FAttachmentTransformRules::KeepRelativeTransform);
	WeaponOffhandMesh->SetVisibility(false);

	// Configure Mesh
	SetupSKComponentsWithCollision(WeaponSkeletalMesh);
	SetupSMComponentsWithCollision(WeaponStaticMesh);
	SetupSMComponentsWithCollision(WeaponOffhandMesh);
}

// Called when the game starts or when spawned
void AWeapon_Master::BeginPlay()
{
	Super::BeginPlay();

	OnRemoveGear.AddDynamic(this, &AWeapon_Master::RemoveWeapon);
}

void AWeapon_Master::OnHit(UObject* CharacterMaster)
{

}

// Custom code when removing binding
void AWeapon_Master::RemoveWeapon()
{
	WeaponSkeletalMesh->SetVisibility(false);
	WeaponStaticMesh->SetVisibility(false);
	WeaponOffhandMesh->SetVisibility(false);
}



