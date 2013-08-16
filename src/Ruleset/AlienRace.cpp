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
#include "AlienRace.h"

namespace OpenXcom
{

/**
 * Creates a blank alien race.
 * @param id String defining the id.
 */
AlienRace::AlienRace(const std::string &id): _id(id), _members()
{
}

AlienRace::~AlienRace()
{
}

/**
 * Loads the alien race from a YAML file.
 * @param node YAML node.
 */
void AlienRace::load(const YAML::Node &node)
{
	_id = node["id"].as<std::string>(_id);
	_members = node["members"].as<std::vector<std::string>>(_members);
}

/**
 * Returns the language string that names
 * this alien race. Each race has a unique name.
 * @return Race name.
 */
std::string AlienRace::getId() const
{
	return _id;
}

/**
 * Gets a certain member of this alien race family.
 * @param id The members id.
 * @return The members name.
 */
std::string AlienRace::getMember(int id) const
{
	return _members[id];
}

}
