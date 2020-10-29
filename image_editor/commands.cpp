#include "commands.h"
#include "executor.h"

void LoadCommand::execute(Executor& executor)
{
    executor.load(m_name, m_filename);
}

void StoreCommand::execute(Executor& executor)
{
    executor.store(m_name, m_filename);
}

void BlurCommand::execute(Executor& executor)
{
    executor.blur(m_fromName, m_toName, m_size);
}

void ResizeCommand::execute(Executor& executor)
{
    executor.resize(m_fromName, m_toName, m_newWidth, m_newHeight);
}

void HelpCommand::execute(Executor& executor)
{
    executor.help();
}

void QuitCommand::execute(Executor& executor)
{
    executor.quit();
}
