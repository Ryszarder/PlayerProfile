#include "Player.h"
#include <iostream>

Player::Player()
{
	m_nHealth = 100;
}

int Player::GetHealth()
{
	return m_nHealth;
}

void Player::SetHealth(int nHealth)
{
	m_nHealth = nHealth;
}