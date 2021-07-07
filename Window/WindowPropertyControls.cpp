#include "WindowPropertyControls.h"
#include "ui_WindowPropertyControls.h"

WindowPropertyControls::WindowPropertyControls() :
    ui(new Ui::WindowPropertyControls)
{
    ui->setupUi(this);
}

WindowPropertyControls::~WindowPropertyControls()
{
    delete ui;
}

QString WindowPropertyControls::windowType()
{
    return "PropertyControls";
}

QString WindowPropertyControls::getWindowType() const
{
    return windowType();
}
