// Fill out your copyright notice in the Description page of Project Settings.

#include "DZNStu_ACNetBasePropCheck.h"
#include "UnrealNetwork.h"
//#include "World.h"

// Sets default values
ADZNStu_ACNetBasePropCheck::ADZNStu_ACNetBasePropCheck(const FObjectInitializer& objs)
	:Super(objs)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Use  NetWork Sync 
	bReplicates = true;
	//bReplicateInstigator = 

	showInfoCom = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ShowText"));
	showInfoCom->SetupAttachment(RootComponent);
	showInfoCom->RelativeLocation = FVector(0, 0, 0.0f);
	showInfoCom->RelativeScale3D = FVector(1, 1, 1.0f);
	showInfoCom->SetIsReplicated(true);

	//λ�ú���תͬ��
	bReplicateMovement = true;

	
}

// Called when the game starts or when spawned
void ADZNStu_ACNetBasePropCheck::BeginPlay()
{
	AActor::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(mCampluteSyncRep_TH, this,&ADZNStu_ACNetBasePropCheck::CampluteRandom, 1, true, 0.0f);
	
}



void ADZNStu_ACNetBasePropCheck::CampluteRandom()
{
	//ServerRun
	if (Role == ROLE_Authority)
	{
		SyncCampluteRandomResult();
	}
	//ClineRunOther
	/*if ()
	{

	}*/
}

bool ADZNStu_ACNetBasePropCheck::SyncCampluteRandomResult_Validate()
{
	return true;
}

void ADZNStu_ACNetBasePropCheck::SyncCampluteRandomResult_Implementation()
{
	mSyncReplicated = FMath::RandRange(0.0f, 1.0f);
}

// Called every frame
void ADZNStu_ACNetBasePropCheck::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);
	//ע�� ��Ҫֱ������Text, ����SetText����ִ�������ı����ݣ�Ȼ������Ⱦ���¡���Ȼ��Ⱦ�Ͳ�����
	//��ȻΪ���Ż� Ҳ��������һ��Ѻ�ͬһ��һ��showInfoCom->MarkRenderStateDirty();
	showInfoCom->SetText(FText::FromString(FString::Printf(TEXT("CurrValue = %f"), mSyncReplicated)));
	
	//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, FString::Printf(TEXT("CurrValue = %f"), mSyncReplicated));
}

void ADZNStu_ACNetBasePropCheck::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	AActor::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ADZNStu_ACNetBasePropCheck, mSyncReplicated);
}
