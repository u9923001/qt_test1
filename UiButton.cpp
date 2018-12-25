#include "UiButton.h"

UiButton::UiButton(QWidget *parent) : QWidget(parent)
{
    _widget = new QWidget();
    _button = new QPushButton("Button");
    _layout = new QVBoxLayout(_widget);

    _initState = false;
    this->ChangeButtonType(Standard);
    _initState = true;

    _layout->addWidget(_button);
    setLayout(_layout);
}

UiButton::UiButton(ButtonType type, QWidget *parent) : QWidget(parent)
{
    _widget = new QWidget();
    _button = new QPushButton("Button");
    _layout = new QVBoxLayout(_widget);

    _initState = false;
    this->ChangeButtonType(type);
    _initState = true;

    _layout->addWidget(_button);
    setLayout(_layout);
}

UiButton::~UiButton()
{
    delete _button;
    delete _widget;
}

void UiButton::ChangeButtonType(ButtonType type)
{
    if(_initState){
        switch(type){
        case Standard:
            _buttonType = Standard;
            this->SetButtonIcon("", QSize(0, 0));
        break;
        case Icon:
            _buttonType = Icon;
            this->SetText("");
        break;
        case LabelIcon:
            _buttonType = LabelIcon;
        break;
        }
    }else{
        switch(type){
        case Standard:
            _buttonType = Standard;
            setupButton();
        break;
        case Icon:
            _buttonType = Icon;
            setupIcon();
        break;
        case LabelIcon:
            _buttonType = LabelIcon;
            setupLabelIcon();
        break;
        }
    }
}

void UiButton::SetText(QString str)
{
    _button->setText(str);
}

void UiButton::SetButtonSize(QSize size)
{
    _widget->setFixedSize(size);
    _button->setFixedSize(size);
}


void UiButton::SetButtonIcon(QString str, QSize size){
    _button->setIcon(QIcon(str));
    _button->setIconSize(size);
}

void UiButton::SetButtonStyle(QString str)
{
    _styleButton = str;
}

void UiButton::SetButtonHoverStyle(QString str)
{
    _style1ButtonHover = str;
}

void UiButton::SetButtonPressedStyle(QString str)
{
    _style1ButtonPressed = str;
}

void UiButton::ButtonLayout()
{
    _button->setStyleSheet(_styleButton+_style1ButtonHover+_style1ButtonPressed);
}

void UiButton::setupButton()
{
    this->SetButtonSize(QSize(86,36));

    this->SetButtonStyle("QPushButton{background-color: #e0e1e2; color: rgba(0,0,0,0.6); font: 12pt 'Times New Roman'; border:nonw; border-radius:4px;}");
    this->SetButtonHoverStyle("QPushButton:hover{background-color: #c0c1c2;}");
    this->SetButtonPressedStyle("QPushButton:focus:pressed{background-color: #9b9c9c;}");
    this->ButtonLayout();
}

void UiButton::setupIcon()
{
    this->SetButtonSize(QSize(36,36));
    this->SetText("");

    this->SetButtonStyle("QPushButton{background-color: #e0e1e2; color: rgba(0,0,0,0.6); font: 12pt 'Times New Roman'; border:nonw; border-radius:4px;}");
    this->SetButtonHoverStyle("QPushButton:hover{background-color: #c0c1c2;}");
    this->SetButtonPressedStyle("QPushButton:focus:pressed{background-color: #9b9c9c;}");
    this->ButtonLayout();

    this->SetButtonIcon("icons8-oak-tree-24.png", QSize(36, 36));
}

void UiButton::setupLabelIcon()
{
    this->SetButtonSize(QSize(86+36,36));
    this->SetText("  Button");

    this->SetButtonStyle("QPushButton{background-color: #e0e1e2; color: rgba(0,0,0,0.6); font: 12pt 'Times New Roman'; border:nonw; border-radius:4px;}");
    this->SetButtonHoverStyle("QPushButton:hover{background-color: #c0c1c2;}");
    this->SetButtonPressedStyle("QPushButton:focus:pressed{background-color: #9b9c9c;}");
    this->ButtonLayout();

    this->SetButtonIcon("icons8-oak-tree-24.png", QSize(36, 36));
}

