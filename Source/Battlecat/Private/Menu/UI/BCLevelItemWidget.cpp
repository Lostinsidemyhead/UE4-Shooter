// Battlecat Game. All Rights Reserved.

#include "Menu/UI/BCLevelItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UBCLevelItemWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (LevelSelectButton)
    {
        LevelSelectButton->OnClicked.AddDynamic(this, &UBCLevelItemWidget::OnLevelItemClicked);
        LevelSelectButton->OnHovered.AddDynamic(this, &UBCLevelItemWidget::OnLevelItemHover);
        LevelSelectButton->OnUnhovered.AddDynamic(this, &UBCLevelItemWidget::OnLevelItemUnhover);
    }
}

void UBCLevelItemWidget::OnLevelItemClicked()
{
    OnLevelSelected.Broadcast(LevelData);
}

void UBCLevelItemWidget::SetLevelData(const FLevelData& Data)
{
    LevelData = Data;

    if (LevelNameTextBlock)
    {
        LevelNameTextBlock->SetText(FText::FromName(Data.LevelDisplayName));
    }

    if (LevelImage)
    {
        LevelImage->SetBrushFromTexture(Data.LevelThumb);
    }
}

void UBCLevelItemWidget::SetSelected(bool IsSelected)
{
    if (LevelImage)
    {
        LevelImage->SetColorAndOpacity(IsSelected ? FLinearColor::Red : FLinearColor::White);
    }
}

void UBCLevelItemWidget::OnLevelItemHover()
{
    if (FrameImage)
    {
        FrameImage->SetVisibility(ESlateVisibility::Visible);
    }
}

void UBCLevelItemWidget::OnLevelItemUnhover()
{
    if (FrameImage)
    {
        FrameImage->SetVisibility(ESlateVisibility::Hidden);
    }
}