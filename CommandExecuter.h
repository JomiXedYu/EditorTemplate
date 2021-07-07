#ifndef COMMANDEXECUTER_H
#define COMMANDEXECUTER_H

#include <stack>

class ICommand
{
public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

class CommandExecuter
{
private:
    int capicity_;
    std::stack<ICommand*> undo_stack_;
    std::stack<ICommand*> redo_stack_;
public:
    bool IsUndoEmpty() const;
    bool IsRedoEmpty() const;
public:
    explicit CommandExecuter(int capicity);
    void Execute(ICommand* cmd);
    void Redo();
    void Undo();
};


#endif // !COMMANDEXECUTER_H
