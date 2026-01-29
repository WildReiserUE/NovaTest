// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/NT_Button.h"

#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"

void UNT_Button::UpdateName(FString Value)
{
	Text->SetText(FText::FromString(Value));
}

void UNT_Button::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	UButton* General = WidgetTree->ConstructWidget<UButton>();
		General->SetBackgroundColor(FLinearColor(1,0.5,0,1));
		General->OnClicked.AddDynamic(this,&UNT_Button::OnButtonClicked);
	WidgetTree->RootWidget = General;
	Text = WidgetTree->ConstructWidget<UTextBlock>();
	Text->SetJustification(ETextJustify::Center);
	General->AddChild(Text);
}

void UNT_Button::OnButtonClicked()
{
	OnClickedDelegate.Broadcast(Index);
}
