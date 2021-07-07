#include "WindowOutliner.h"
#include "ui_WindowOutliner.h"

WindowOutliner::WindowOutliner() :
    ui(new Ui::WindowOutliner)
{
    ui->setupUi(this);
}

WindowOutliner::~WindowOutliner()
{
    delete ui;
}

QString WindowOutliner::getWindowType() const
{
    return windowType();
}

QString WindowOutliner::windowType()
{
    return "Outliner";
}
