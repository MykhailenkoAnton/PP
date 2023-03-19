enum class eAction
{
    NONE,
    DOWN,
    UP
};

class PingPongGame
{

public:
    void run();
    void UserChoice();

    eAction getUserChoice();
};