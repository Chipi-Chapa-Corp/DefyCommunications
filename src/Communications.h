/*
 * Copyright (C) 2024  Dygma Lab S.L.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Gustavo Gomez Lopez @Noteolvides
 *
 */

#ifndef _COMMUNICATIONS_H_
#define _COMMUNICATIONS_H_


#include "Communications_protocol.h"
#include "Callback.h"

using namespace Communications_protocol;


class Communications {
 public:
  void init();

  void run();

  bool isWiredLeftAlive();
  bool isWiredRightAlive();

  bool sendPacket(Packet data);
  // Select LEFT/RIGHT with KEYSCANNER_DEFY_LEFT/RIGHT. Returns the live wired,
  // RF or BLE destination, or UNKNOWN when there is no active transport.
  Devices connectedSideDevice(Devices side);
  // Application overlays suppress competing output before it enters a queue.
  using PacketFilter = bool (*)(const Packet &);
  void setPacketFilter(PacketFilter filter) { packet_filter_ = filter; }
  bool sendPacketHostConnection( void );

  void get_keyscanner_configuration();

   void request_keyscanner_layers();

   bool is_host_connected();

  BindingCallbacks<Commands, Packet> callbacks{};
 private:
  PacketFilter packet_filter_ = nullptr;
};

extern Communications Communications;


#endif  //_COMMUNICATIONS_H_
