///////////////////////////////////////////////////////////////////////////////
//
//                          IMPORTANT NOTICE
//
// The following open source license statement does not apply to any
// entity in the Exception List published by FMSoft.
//
// For more information, please visit:
//
// https://www.fmsoft.cn/exception-list
//
//////////////////////////////////////////////////////////////////////////////
/*
** This file is a part of mg-demos package.
**
** Copyright (C) 2010 ~ 2019 FMSoft (http://www.fmsoft.cn).
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
/*!============================================================================
 * @file ContentValues.hh
 * @Synopsis This class is used to store a set of values that the ContentProvider can process.
 * @author DongKai
 * @version 1.0
 *  Company: Beijing FMSoft Technology Co., Ltd.
 */

#ifndef  CONTENTVALUES_INC
#define  CONTENTVALUES_INC

#include <map>
#include <string>
#include <vector>
#include "boost/any.hpp"

typedef std::map<std::string, boost::any> ExtraMap;

class ContentValues {
public:
    typedef std::vector<std::string> Strings;
    static bool isNull(const boost::any& operand) {
        return operand.empty();
    }

    static bool isInteger(const boost::any& operand) {
        return (operand.type() == typeid(int));
    }

    static bool isReal(const boost::any& operand) {
        return (operand.type() == typeid(float)
                || operand.type() == typeid(double));
    }

    static bool isString(const boost::any& operand) {
        return boost::any_cast<std::string>(&operand);
    }

    ContentValues() {}
    virtual ~ContentValues() {
        m_data.clear();
    }

    void clear() { m_data.clear(); }
    bool containsKey(const std::string& key) { return (m_data.find(key) != m_data.end()); }
    const boost::any get(const std::string& key) const;
//    bool getBoolean(const std::string& key, bool defaultValue) const;
    double getAsReal(const std::string& key, double defaultValue) const;
    int getAsInteger(const std::string& key, int defaultValue) const;
    std::string getAsString(const std::string& key) const;

    void put(const std::string& key, boost::any value);
//    void putBoolean(const std::string& key, bool value);
    void putReal(const std::string& key, double value);
    void putFloat(const std::string& key, float value);
    void putInteger(const std::string& key, int value);
    void putString(const std::string& key, const std::string& value);

    Strings keySet() const;

    bool isEmpty() const { return m_data.empty(); }
    size_t count() const {return m_data.size();}
private:
    ExtraMap m_data;
};

#define StringArray ContentValues::Strings

#endif   /* ----- #ifndef CONTENTVALUES_INC  ----- */

