class Sensor
{
  public:
    Sensor();
    double* GetData();
    int GetSize();
    virtual void FillData() = 0;
  private:
    int dataSize;
    double dataSet[];
    
};

