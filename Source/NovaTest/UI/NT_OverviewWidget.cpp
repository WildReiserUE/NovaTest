// Fill out your copyright notice in the Description page of Project Settings.


#include "NT_OverviewWidget.h"

#include "NT_PartSlot.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"

void UNT_OverviewWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UNT_OverviewWidget::AddToList(int Index, FString Name, UStaticMeshComponent* Mesh)
{
	if(!PartsList) return;

	UNT_PartSlot* PartSlot = WidgetTree->ConstructWidget<UNT_PartSlot>();
	PartSlot->UpdatePartName(Index,Name, Mesh);

	if(!PartSlot->OnHovered.IsBound())
		PartSlot->OnHovered.AddDynamic(this, &UNT_OverviewWidget::Hovered);
	if(!PartSlot->OnShowSingle.IsBound())
		PartSlot->OnShowSingle.AddDynamic(this, &UNT_OverviewWidget::Single);

	PartsList->AddChild(PartSlot);
}

void UNT_OverviewWidget::Hovered(UStaticMeshComponent* Component)
{
	OnSendInfo.Broadcast(Component);
}

void UNT_OverviewWidget::Single(UStaticMeshComponent* Component)
{
	OnSingleInfo.Broadcast(Component);
}

void UNT_OverviewWidget::ClearList()
{
	PartsList->ClearChildren();
}

void UNT_OverviewWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	UCanvasPanel* CanvasPanel = WidgetTree->ConstructWidget<UCanvasPanel>();
	CanvasPanel->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	WidgetTree->RootWidget = CanvasPanel;

	UOverlay* Overlay = WidgetTree->ConstructWidget<UOverlay>();
	auto Cs = CanvasPanel->AddChildToCanvas(Overlay);
		FAnchors Anchors;
		Anchors.Minimum = FVector2D(0,0);
		Anchors.Maximum = FVector2D(0,1);
		Cs->SetAutoSize(true);
		Cs->SetAnchors(Anchors);
		Cs->SetOffsets(FMargin(0,0,0,0));

	UBorder* Border = WidgetTree->ConstructWidget<UBorder>();
	Border->SetPadding(FMargin(0,0,0,0));
	Border->SetBrushColor(FLinearColor(0.01,0.01,0.01,1));
	auto Os = Overlay->AddChildToOverlay(Border);
		Os->SetVerticalAlignment(VAlign_Fill);
		Os->SetHorizontalAlignment(HAlign_Fill);

	USizeBox* SizeBox = WidgetTree->ConstructWidget<USizeBox>();
	SizeBox->SetWidthOverride(550);
	SizeBox->SetMaxDesiredWidth(550);
	Overlay->AddChildToOverlay(SizeBox);

	UVerticalBox* VerticalBox1 = WidgetTree->ConstructWidget<UVerticalBox>();
	ButtonComplect = WidgetTree->ConstructWidget<UButton>();
	ButtonComplect->SetBackgroundColor(FLinearColor(1,0.5,0,1));

	UTextBlock* ComplectText = WidgetTree->ConstructWidget<UTextBlock>();
	ComplectText->SetText(FText::FromString("planetary reductor"));
	ComplectText->SetJustification(ETextJustify::Center);
	ButtonComplect->AddChild(ComplectText);
	auto Bs = VerticalBox1->AddChildToVerticalBox(ButtonComplect);
		Bs->SetHorizontalAlignment(HAlign_Center);
		Bs->SetPadding(FMargin(0,0,0,50));

	PartsList = WidgetTree->ConstructWidget<UScrollBox>();
	PartsList->SetAllowOverscroll(true);
		auto Vs = VerticalBox1->AddChildToVerticalBox(PartsList);
		FSlateChildSize Size;
		Size.SizeRule = ESlateSizeRule::Fill;
		Vs->SetSize(Size);
		Vs->SetPadding(FMargin(40,0,40,0));

	Os = Overlay->AddChildToOverlay(VerticalBox1);
		Os->SetHorizontalAlignment(HAlign_Fill);
		Os->SetPadding(FMargin(0,50,0,0));

	ButtonBack = WidgetTree->ConstructWidget<UButton>();
	ButtonBack->SetBackgroundColor(FLinearColor(1,0.5,0,1));
	UTextBlock* ButtonText = WidgetTree->ConstructWidget<UTextBlock>();
	ButtonText->SetText(FText::FromString("Back"));
	ButtonBack->AddChild(ButtonText);
		Os = Overlay->AddChildToOverlay(ButtonBack);
		Os->SetVerticalAlignment(VAlign_Bottom);
		Os->SetHorizontalAlignment(HAlign_Fill);
		Os->SetPadding(FMargin(100,0,100,50));
}
