#include "CommandExecuter.h"

bool CommandExecuter::IsUndoEmpty() const
{
    return this->undo_stack_.size() == 0;
}

bool CommandExecuter::IsRedoEmpty() const
{
    return this->redo_stack_.size() == 0;
}

CommandExecuter::CommandExecuter(int capicity) : capicity_(capicity)
{

}

void CommandExecuter::Execute(ICommand *cmd)
{
    cmd->Execute();
    this->undo_stack_.push(cmd);
    if(!this->IsRedoEmpty()) {
        decltype(this->redo_stack_)().swap(this->redo_stack_);
    }
}

void CommandExecuter::Redo()
{

}
