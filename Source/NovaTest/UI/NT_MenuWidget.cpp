// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_MenuWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Spacer.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

void UNT_MenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	ButtonStart->OnClicked.Broadcast();
	ButtonExit->OnClicked.Broadcast();
}

void UNT_MenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	bIsFocusable = true;
	UCanvasPanel* CanvasPanel = WidgetTree->ConstructWidget<UCanvasPanel>();
	WidgetTree->RootWidget = CanvasPanel;

	UVerticalBox* VBox1 = WidgetTree->ConstructWidget<UVerticalBox>();
	auto CPs = CanvasPanel->AddChildToCanvas(VBox1);
	FAnchors Anchors;
	Anchors.Minimum = FVector2D(0,1);
	Anchors.Maximum = FVector2D(0,1);
		CPs->SetAnchors(FAnchors(Anchors));
		CPs->SetPosition(FVector2D(200,-150));
		CPs->SetAlignment(FVector2D(0,1));
		CPs->SetSize(FVector2D(270,170));

	ButtonStart = WidgetTree->ConstructWidget<UButton>();
	ButtonStart->BackgroundColor = FLinearColor(1,0.5,0,1);
	UTextBlock* StartBlock = WidgetTree->ConstructWidget<UTextBlock>();
	StartBlock->SetText(FText::FromString("Overview"));
	ButtonStart->AddChild(StartBlock);
	auto Vs = VBox1->AddChildToVerticalBox(ButtonStart);
		FSlateChildSize Size;
		Size.SizeRule = ESlateSizeRule::Fill;
		Vs->SetSize(Size);

	USpacer* Spacer = WidgetTree->ConstructWidget<USpacer>();
	Spacer->Size = FVector2D(1,50);
	VBox1->AddChildToVerticalBox(Spacer);

	ButtonExit = WidgetTree->ConstructWidget<UButton>();
	ButtonExit->BackgroundColor = FLinearColor(1,0.5,0,1);
	UTextBlock* ExitBlock = WidgetTree->ConstructWidget<UTextBlock>();
	ExitBlock->SetText(FText::FromString("Exit"));
	ButtonExit->AddChild(ExitBlock);
		Vs = VBox1->AddChildToVerticalBox(ButtonExit);
		Vs->SetSize(Size);
}
