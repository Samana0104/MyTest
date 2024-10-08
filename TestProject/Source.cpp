#include <iostream>
#include <vector>
using namespace std;

class Observer
{
public:
	virtual void update() = 0;
};

class DisplayElement
{
public:
	virtual void display() = 0;
};

class Subject
{
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
};

class WeatherData : public Subject
{
private:
	vector<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;

public:
	WeatherData() :
		temperature(0.f), humidity(0.f), pressure(0.f)
	{ 
		this->observers.reserve(100);
	}

	void registerObserver(Observer * o)
	{
		this->observers.push_back(o);
	}

	void removeObserver(Observer * o)
	{
		this->observers.erase(
			std::find(this->observers.begin(), this->observers.end(), o));
	}

	void notifyObservers()
	{
		for(auto obIter = observers.begin(); obIter != observers.end(); ++obIter)
			(*obIter)->update();
	}


	void measurementsChanged()
	{
		notifyObservers();
	}

	void setMeasurements(float _temperature, float _humidity, float _pressure)
	{
		this->temperature = _temperature;
		this->humidity = _humidity;
		this->pressure = _pressure;
		measurementsChanged();
	}

	float getTemperature() const
	{
		return temperature;
	}

	float getHumidity() const
	{
		return humidity;
	}
};

class CurrentConditionDisplay : public Observer, DisplayElement
{
private:
	float temperature;
	float humidity;
	WeatherData &weatherData;
public:
	CurrentConditionDisplay(WeatherData& _weatherData) : weatherData(_weatherData)
	{
		weatherData.registerObserver(this);
	}

	void update()
	{
		this->temperature = weatherData.getTemperature();
		this->humidity = weatherData.getHumidity();
		display();
	}

	void display()
	{
		cout << "현재 상태 : 온도 " << temperature << "F, 습도 " << humidity << "%" << endl;
	}

};

class StatisticsDisplay : public Observer, DisplayElement
{
private:
	float temperature;
	float humidity;
	WeatherData &weatherData;
public:
	StatisticsDisplay(WeatherData& _weatherData) : weatherData(_weatherData)
	{
		weatherData.registerObserver(this);
	}

	void update()
	{
		this->temperature = weatherData.getTemperature();
		this->humidity = weatherData.getHumidity();
		display();
	}

	void display()
	{
		cout << "현재 상태 : 온도 " << temperature << "F, 습도 " << humidity << "%" << endl;
	}
};

class ForecastDisplay : public Observer, DisplayElement
{
private:
	float temperature;
	float humidity;
	WeatherData &weatherData;
public:
	ForecastDisplay(WeatherData& _weatherData) : weatherData(_weatherData)
	{
		weatherData.registerObserver(this);
	}

	void update()
	{
		this->temperature = weatherData.getTemperature();
		this->humidity = weatherData.getHumidity();
		display();
	}

	void display()
	{
		cout << "현재 상태 : 온도 " << temperature << "F, 습도 " << humidity << "%" << endl;
	}
};

int main()
{
	WeatherData weatherData;
	
	CurrentConditionDisplay currentDisplay(weatherData);
	StatisticsDisplay statisticsDisplay(weatherData);
	ForecastDisplay forecastDisplay(weatherData);

	weatherData.setMeasurements(80, 65, 30.4f);
	weatherData.setMeasurements(82, 60, 29.2f);
	weatherData.setMeasurements(78, 90, 29.2f);
	return 0;
}