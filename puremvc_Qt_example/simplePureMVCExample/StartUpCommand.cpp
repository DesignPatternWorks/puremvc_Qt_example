#include "StartUpCommand.h"
#include "AppFacade.h"
#include "loginProxy.h"
#include "loginMediator.h"

StartUpCommand::StartUpCommand()
      :SimpleCommand()
{
}

StartUpCommand::~StartUpCommand(void)
{
}

void StartUpCommand::execute(INotification const& notification)
{
    const void * pLoginView = notification.getBody();

    IFacade &facade = AppFacade::getInstance();

    /* ע�����Model��
    */
    facade.registerProxy(new LoginProxy());

    /**
    * ע��ViewComponents����UI������н�����
    */
    facade.registerMediator(new LoginMediator(pLoginView));
}