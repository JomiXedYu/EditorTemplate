#include "WindowStage.h"
#include "ui_WindowStage.h"

WindowStage::WindowStage() :
    ui(new Ui::WindowStage)
{
    ui->setupUi(this);
}

WindowStage::~WindowStage()
{
    delete ui;
}

QString WindowStage::windowType()
{
    return "Stage";
}

QString WindowStage::getWindowType() const
{
    return windowType();
}
