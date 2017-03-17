#pragma once
#include "PlayerCard.h"

enum EventCardType
{
	Airlift,
	OneQuietNight,
	ResilientPopulation,
	GovernmentGrant,
	Forecast
};

class EventCard : public PlayerCard
{
public:
	EventCard(EventCardType type);
	~EventCard();

	void playCard();
	std::string getSurfaceName();

private:
	EventCardType _eventType;
};
