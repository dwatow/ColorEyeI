<<<<<<< HEAD
#include "stdafx.h"
#include <cmath>
#include "CircleArc.h"

void CircleArc::DrawArc(CPoint& endpt)
{
	int oX, oY;

	oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
	oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
	if (m_Percent > 0 && m_Percent <= 25)
	{
		oX = (int)(m_nRadius / cos(0.0628318 * (m_Percent+50)));
		oY = (int)(m_nRadius / sin(0.0628318 * (m_Percent+50)));
	} 
	else if (m_Percent > 25 && m_Percent <= 50)
	{
	oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
	oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
	} 
	else if (m_Percent > 50 && m_Percent <= 75)
	{
		oX = (int)(m_nRadius / cos(0.0628318 * (m_Percent-50)));
		oY = (int)(m_nRadius / sin(0.0628318 * (m_Percent-50)));
	} 
	else if (m_Percent > 75 && m_Percent < 100)
	{
		oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
		oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
	}
	endpt.x = oX + m_nCenter.x;
	endpt.y = oY + m_nCenter.y;
=======
#include "stdafx.h"
#include <cmath>
#include "CircleArc.h"

void CircleArc::DrawArc(CPoint& endpt)
{
	int oX, oY;

	oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
	oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
	if (m_Percent > 0 && m_Percent <= 25)
	{
		oX = (int)(m_nRadius / cos(0.0628318 * (m_Percent+50)));
		oY = (int)(m_nRadius / sin(0.0628318 * (m_Percent+50)));
	} 
	else if (m_Percent > 25 && m_Percent <= 50)
	{
	oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
	oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
	} 
	else if (m_Percent > 50 && m_Percent <= 75)
	{
		oX = (int)(m_nRadius / cos(0.0628318 * (m_Percent-50)));
		oY = (int)(m_nRadius / sin(0.0628318 * (m_Percent-50)));
	} 
	else if (m_Percent > 75 && m_Percent < 100)
	{
		oX = (int)(m_nRadius / cos(0.0628318 * m_Percent));
		oY = (int)(m_nRadius / sin(0.0628318 * m_Percent));
	}
	endpt.x = oX + m_nCenter.x;
	endpt.y = oY + m_nCenter.y;
>>>>>>> b5425c75ef070be7770a30afe5b503213bd2584b
}