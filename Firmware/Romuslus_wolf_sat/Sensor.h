#ifndef SENSOR_H
#define SENSOR_H
class Sensor
{
  public:
    Sensor();
    Sensor(int in_dataSize);
    ~Sensor();
    double* GetData();
    int GetSize();
    virtual void FillData() = 0;
  protected:
    double* dataSet;
  private:
    int dataSize;
//    double* dataSet;
    
};

#endif
