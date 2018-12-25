#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class UiButton : public QWidget
{
    Q_OBJECT
public:

    enum ButtonType
    {
      Standard,
      Icon,
      LabelIcon,
    };
    explicit UiButton(QWidget *parent = 0);
    explicit UiButton(ButtonType, QWidget *parent = 0);
    ~UiButton();
    void SetText(QString);
    void SetButtonSize(QSize);
    void SetButtonIcon(QString, QSize);
    void SetButtonStyle(QString);
    void SetButtonHoverStyle(QString);
    void SetButtonPressedStyle(QString);
    void ButtonLayout();
    void ChangeButtonType(ButtonType);


private:
    QWidget* _widget;
    QVBoxLayout* _layout;
    QPushButton* _button;
    QPixmap _pixmap;
    QString _styleButton;
    QString _style1ButtonHover;
    QString _style1ButtonPressed;
    ButtonType _buttonType;
    bool _initState;

    void setupButton();
    void setupIcon();
    void setupLabelIcon();

signals:

public slots:
};

#endif // UIBUTTON_H
