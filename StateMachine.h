#define STOP_STATE 0
#define PENDING_STATE 1
#define BUSY_STATE 2

#define ONLINE_STATE 0
#define OFFLINE_STATE 1

#define TRANSATION_BUSY_STATE 0
#define TRANSATION_FREE_STATE 1

#define TRANSATION_OK 0
#define TRANSATION_ERROR 1
class StateMachine{
private:
    int m_currentState;

    int m_normalTransationState;
    int m_logTransationState;

    int m_systemOnlineState;
    int m_logOnlineState;
    
    long lastTransationTime;//microseconds
public:
    void Init();
    void Loop();
    void EventSystemOnline();
    void EventLogOnline();
    void EventTransation();
}
void StateMachine::Init()
{
    m_currentState = STOP_STATE;
    m_systemOnlineState = OFFLINE_STATE;
    m_logOnlineState = OFFLINE_STATE;

    m_normalTransationState = TRANSATION_FREE_STATE;
    m_logTransationState = TRANSATION_FREE_STATE;

    
    // set lastTransationTime to current
}
void StateMachine::Loop()
{
    if(m_currentState == STOP_STATE){
        if(m_systemOnlineState == ONLINE_STATE && m_logOnlineState == ONLINE_STATE){
            m_currentState = PENDING_STATE;
        }
    }

    else if(m_currentState == PENDING_STATE){
        if(m_normalTransationState == TRANSATION_BUSY_STATE && m_logTransationState == TRANSATION_BUSY_STATE){
            m_currentState = BUSY_STATE;
        }
    }

    else if(m_currentState == BUSY_STATE){
        if(m_normalTransationState == TRANSATION_FREE_STATE && m_normalTransationState == TRANSATION_FREE_STATE){
            m_currentState = PENDING_STATE;
        }
        else{
            //long currentTime = fun()//get current time
            if (currentTime - lastTransationTime >= 30*1000){
                m_currentState = PENDING_STATE;
                m_normalTransationState = TRANSATION_FREE_STATE;
                m_normalTransationState = TRANSATION_FREE_STATE;
            }
        }

    }
    
    
}
void StateMachine::EventSystemOnline()
{
    m_systemOnlineState = ONLINE_STATE;
}
void StateMachine::EventLogOnline()
{
    m_logOnlineState = ONLINE_STATE;
}
void StateMachine::EventTransation()
{
    m_normalTransationState = TRANSATION_BUSY_STATE;
    m_logTransationState = TRANSATION_BUSY_STATE;
    int result = TRANSATION_OK;

    //lastTransationTime = fun()//get current time

    //do transation now
    //...
    //... result check
    //transation finished

    if(reuslt == TRANSATION_ERROR){
        m_currentState = STOP_STATE;
    }
    m_normalTransationState = TRANSATION_FREE_STATE;
    m_logTransationState = TRANSATION_FREE_STATE;
   
}