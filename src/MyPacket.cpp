/* Copyright 2013-2019 Homegear GmbH
 *
 * Homegear is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Homegear is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Homegear.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */

#include "MyPacket.h"

#include "GD.h"


namespace MyFamily
{
MyPacket::MyPacket()
{
}

MyPacket::MyPacket(std::string& payload) : _payload(payload)
{

}

MyPacket::~MyPacket()
{
	_payload.clear();
}

std::string& MyPacket::hexString()
{
    return _payload;
}

std::string& MyPacket::culHexString()
{
    if(!_culpacket.empty()) return _culpacket;
    // The CUL needs the address bytes 1 and 3 swapped - FHEM does that, too.
    if(_payload.length() >= 14)
    {
        _culpacket = _payload;
        _culpacket[8] = _payload[12];
        _culpacket[9] = _payload[13];
        _culpacket[12] = _payload[8];
        _culpacket[13] = _payload[9];
    }
    return _culpacket;
}
}
