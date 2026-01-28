// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_PartSlot.h"

#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/TextBlock.h"

void UNT_PartSlot::UpdatePartName(int Value, FString Name,UStaticMeshComponent* Mesh)
{
	if(PartBlock)
	{
		Component = Mesh;
		PartBlock->SetText(FText::FromString(FString::FromInt(Value + 1) + " " + Name));
	}
}

void UNT_PartSlot::SendInfo()
{
	OnHovered.Broadcast(Component);
}

void UNT_PartSlot::ClearInfo()
{
	OnHovered.Broadcast(nullptr);
}

void UNT_PartSlot::ShowSingle()
{
	OnShowSingle.Broadcast(Component);
}

void UNT_PartSlot::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	Button = WidgetTree->ConstructWidget<UButton>();
	WidgetTree->RootWidget = Button;

	PartBlock = WidgetTree->ConstructWidget<UTextBlock>();
	Button->AddChild(PartBlock);
}

void UNT_PartSlot::NativeConstruct()
{
	Super::NativeConstruct();
	if(Button)
	{
		if(!Button->OnPressed.IsBound())
			Button->OnPressed.AddDynamic(this,&UNT_PartSlot::ShowSingle);
		if(!Button->OnHovered.IsBound())
			Button->OnHovered.AddDynamic(this,&UNT_PartSlot::SendInfo);
		if(!Button->OnUnhovered.IsBound())
			Button->OnUnhovered.AddDynamic(this,&UNT_PartSlot::ClearInfo);
	}
}
