/* Copyright 2013-2019 Homegear GmbH
 * Copyright 2021 Andreas Boehler
 * Copyright 2023 Jan-Martin Raemer
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

#include "Cul.h"
#include <homegear-base/BaseLib.h>
#include "../GD.h"
#include "../MyPacket.h"

namespace MyFamily
{

Cul::Cul(std::shared_ptr<BaseLib::Systems::PhysicalInterfaceSettings> settings) : ISomfyInterface(settings)
{
	_out.init(GD::bl);
	_out.setPrefix(GD::out.getPrefix() + "CUL \"" + settings->id + "\": ");
	LibSerial::BaudRate baudrate = LibSerial::BaudRate::BAUD_38400;
	switch(settings->baudrate) {
	case 50:
		baudrate = LibSerial::BaudRate::BAUD_50;
		break;
	case 75:
		baudrate = LibSerial::BaudRate::BAUD_75;
		break;
	case 110:
		baudrate = LibSerial::BaudRate::BAUD_110;
		break;
	case 134:
		baudrate = LibSerial::BaudRate::BAUD_134;
		break;
	case 150:
		baudrate = LibSerial::BaudRate::BAUD_150;
		break;
	case 200:
		baudrate = LibSerial::BaudRate::BAUD_200;
		break;
	case 300:
		baudrate = LibSerial::BaudRate::BAUD_300;
		break;
	case 600:
		baudrate = LibSerial::BaudRate::BAUD_600;
		break;
	case 1200:
		baudrate = LibSerial::BaudRate::BAUD_1200;
		break;
	case 1800:
		baudrate = LibSerial::BaudRate::BAUD_1800;
		break;
	case 2400:
		baudrate = LibSerial::BaudRate::BAUD_2400;
		break;
	case 4800:
		baudrate = LibSerial::BaudRate::BAUD_4800;
		break;
	case 9600:
		baudrate = LibSerial::BaudRate::BAUD_9600;
		break;
	case 19200:
		baudrate = LibSerial::BaudRate::BAUD_19200;
		break;
	case 38400:
		baudrate = LibSerial::BaudRate::BAUD_38400;
		break;
	case 57600:
		baudrate = LibSerial::BaudRate::BAUD_57600;
		break;
	case 115200:
		baudrate = LibSerial::BaudRate::BAUD_115200;
		break;
	case 230400:
		baudrate = LibSerial::BaudRate::BAUD_230400;
		break;
	case 460800:
		baudrate = LibSerial::BaudRate::BAUD_460800;
		break;
	case 500000:
		baudrate = LibSerial::BaudRate::BAUD_500000;
		break;
	case 576000:
		baudrate = LibSerial::BaudRate::BAUD_576000;
		break;
	case 921600:
		baudrate = LibSerial::BaudRate::BAUD_921600;
		break;
	case 1000000:
		baudrate = LibSerial::BaudRate::BAUD_1000000;
		break;
	case 1152000:
		baudrate = LibSerial::BaudRate::BAUD_1152000;
		break;
	case 1500000:
		baudrate = LibSerial::BaudRate::BAUD_1500000;
		break;
	default:
    		_out.printWarning(std::string("Warning: invalid baudrate, defaulting to 38400."));
		break;
	}
	sp.Open(settings->device);
	sp.SetBaudRate(baudrate);
}


Cul::~Cul()
{
	sp.Close();
}

void Cul::sendPacket(std::shared_ptr<BaseLib::Systems::Packet> packet)
{
	std::shared_ptr<MyPacket> myPacket(std::dynamic_pointer_cast<MyPacket>(packet));
	sp.Write("Ys" + myPacket->culHexString() + "\n");
}


void Cul::startListening()
{
	IPhysicalInterface::startListening();
}

void Cul::stopListening()
{
	IPhysicalInterface::stopListening();
}
}
