#ifndef INTERFACE_H
#define INTERFACE_H

class Interface
{
  public:
    Interface();
    bool CheckButton();
    void SetState(int);
    void SetError(bool);
    void SetReady(bool);

  private:
    const int LED_ERROR = 27;
    const int LED_READY = 28;
    const int LED_MULTIR = 32;
    const int LED_MULTIG = 30;
    const int LED_MULTIB = 31;
    const int BUTTON = 29;

    void AllOff();
};
#endif
