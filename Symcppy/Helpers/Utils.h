#pragma once
#pragma warning(disable:4996)
#include "PyEnums.h"
#include <string>
#include <iostream>
#include <stdio.h>

const std::string K_POSITIVE_INF = "oo";
const std::string K_NEGATIVE_INF = "-oo";

const double K_POSITIVE_INF_VALUE = std::numeric_limits<double>::max();
const double K_NEGATIVE_INF_VALUE = std::numeric_limits<double>::min();

typedef unsigned int ArgCount;
typedef unsigned int FunctionIndex;

struct FunctionResult
{
	EStatus result{ EStatus::Error };
	void* value{ nullptr };
};

template<typename T>
std::vector<T> TokenizeString(const std::string& target, const std::string& delimiter)
{
	std::vector<T> holder;

	size_t pos = 0;
	std::string toTokenize = target;
	std::string token;
	while ((pos = toTokenize.find(delimiter)) != std::string::npos)
	{
		token = toTokenize.substr(0, pos);
		holder.emplace_back(token);
		toTokenize.erase(0, pos + delimiter.length());
	}
	if (!toTokenize.empty())
	{
		holder.emplace_back(toTokenize);
	}

	return holder;
}

struct EndPoint
{
	static EndPoint StringToEndPoint(const std::string& target)
	{
		EndPoint result;
		if (target == K_POSITIVE_INF)
		{
			result = { 1, true, true };
		}
		else if (target == K_NEGATIVE_INF)
		{
			result = { -1, true, true };
		}
		else
		{
			result = { atof(target.c_str()), false, false };
		}

		return result;
	}

	void SetIsOpen(char bracket)
	{
		isOpen = (bracket == '(' || bracket == ')');
	}

	double value{ 0 };
	bool isInf{ false };
	bool isOpen{ false };
};

class Interval
{
private:
	static constexpr char K_INTERVAL_DELIMITER[] = ", ";

public:
	Interval(const std::string& intervalString) : m_IntervalString(intervalString) 
	{
		std::vector<std::string> tokens = TokenizeString<std::string>(intervalString, K_INTERVAL_DELIMITER);

		std::string& leftString = tokens.front();
		m_Left = EndPoint::StringToEndPoint(std::string(leftString.begin() + 1, leftString.end()));
		m_Left.SetIsOpen(leftString.front());

		std::string& rightString = tokens.back();
		m_Right = EndPoint::StringToEndPoint(std::string(rightString.begin(), rightString.end() - 1));
		m_Right.SetIsOpen(rightString.back());
	}

	std::string GetIntervalString() const { return m_IntervalString; }
	EndPoint GetLeft() const { return m_Left; }
	EndPoint GetRight() const { return m_Right; }

	friend std::ostream& operator<<(std::ostream& os, const Interval& interval)
	{
		return os << (interval.m_Left.isOpen ? "(" : "[")
			<< (interval.m_Left.isInf ? (interval.m_Left.value > 0 ? K_POSITIVE_INF : K_NEGATIVE_INF) : std::to_string(interval.m_Left.value))
			<< ", "
			<< (interval.m_Right.isInf ? (interval.m_Right.value > 0 ? K_POSITIVE_INF : K_NEGATIVE_INF) : std::to_string(interval.m_Right.value))
			<< (interval.m_Right.isOpen ? ")" : "]");
	}

private:
	std::string m_IntervalString;

	EndPoint m_Left;
	EndPoint m_Right;
};

class Union
{
private:
	static constexpr char K_UNION_DELIMITER[] = "U";

public:
	Union() : m_UnionString("")
	{
	}

	Union(const std::string& unionString) : m_UnionString(unionString) 
	{
		m_Intervals = TokenizeString<Interval>(unionString, K_UNION_DELIMITER);
	}

	std::string GetUnionString() const { return m_UnionString; }
	std::vector<Interval> GetIntervals() const { return m_Intervals; }

	friend std::ostream& operator<<(std::ostream& os, const Union& u)
	{
		for (int i = 0; i < u.m_Intervals.size(); i++)
		{
			const Interval& interval = u.m_Intervals[i];
			if (i == u.m_Intervals.size() - 1)
			{
				return os << interval;
			}
			else
			{
				os << interval << "U";
			}
		}
		
		return os;
	}

private:
	std::string m_UnionString;

	std::vector<Interval> m_Intervals;

};


