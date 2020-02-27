class Sensor
{
  public:
    Sensor();
    Sensor(int in_dataSize);
    double* GetData();
    int GetSize();
    virtual void FillData() = 0;
  private:
    int dataSize;
    double* dataSet;
    
};

