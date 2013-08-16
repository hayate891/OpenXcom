/*
 * Copyright 2010-2013 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "RuleManufacture.h"

namespace OpenXcom
{
/**
 * Create a new Manufacture
 * @param name The unique manufacture name
*/
RuleManufacture::RuleManufacture(const std::string &name) : _name(name), _space(0), _time(0), _cost(0), _listOrder(0)
{
}

/**
 * Loads the manufacture project from a YAML file.
 * @param node YAML node.
 * @param listOrder the list weight for this manufacture.
 */
void RuleManufacture::load(const YAML::Node &node, int listOrder)
{
	_name = node["name"].as<std::string>(_name);
	_category = node["category"].as<std::string>(_category);
	_requires = node["requires"].as<std::vector<std::string>>(_requires);
	_space = node["space"].as<int>(_space);
	_time = node["time"].as<int>(_time);
	_cost = node["cost"].as<int>(_cost);
	_requiredItems = node["requiredItems"].as<std::map<std::string, int>>(_requiredItems);
	_listOrder = node["listOrder"].as<int>(_listOrder);
	if (!_listOrder)
	{
		_listOrder = listOrder;
	}
}

/**
 * Get the unique name of the manufacture
 * @return the name
*/
std::string RuleManufacture::getName () const
{
	return _name;
}

/**
 * Get the category shown in the manufacture list
 * @return the category
*/
std::string RuleManufacture::getCategory () const
{
	return _category;
}

/**
 * Returns the list of research required to
 * manufacture this object.
 * @return List of research IDs.
 */
const std::vector<std::string> &RuleManufacture::getRequirements() const
{
	return _requires;
}

/**
 * Get the required workspace
 * @return the required workspace to start production
*/
int RuleManufacture::getRequiredSpace () const
{
	return _space;
}

/**
 * Get the time needed to manufacture one object
 * @return The time needed to manufacture one object(in man/hour)
*/
int RuleManufacture::getManufactureTime () const
{
	return _time;
}


/**
 * Get the cost of one object
 * @return the cost of manufacturing one object
*/
int RuleManufacture::getManufactureCost () const
{
	return _cost;
}

/**
 * Get the list of items required to manufacture one object
 * @return the list of items required to manufacture one object
*/
const std::map<std::string, int> & RuleManufacture::getRequiredItems() const
{
	return _requiredItems;
}

/**
 * @return the list weight for this manufacture item.
 */
int RuleManufacture::getListOrder() const
{
	return _listOrder;
}
}
