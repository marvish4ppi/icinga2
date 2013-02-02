/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012 Icinga Development Team (http://www.icinga.org/)        *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef TYPERULELIST_H
#define TYPERULELIST_H

namespace icinga
{

struct TypeRule;

/**
 * A list of configuration type rules.
 *
 * @ingroup config
 */
class I2_CONFIG_API TypeRuleList : public Object
{
public:
	typedef shared_ptr<TypeRuleList> Ptr;
	typedef weak_ptr<TypeRuleList> WeakPtr;

	void AddRule(const TypeRule& rule);
	void AddRules(const TypeRuleList::Ptr& ruleList);

	bool FindMatch(const String& name, const Value& value, TypeRuleList::Ptr *subRules);

	size_t GetLength(void) const;

private:
	vector<TypeRule> m_Rules;
};

}

#endif /* TYPERULELIST_H */
