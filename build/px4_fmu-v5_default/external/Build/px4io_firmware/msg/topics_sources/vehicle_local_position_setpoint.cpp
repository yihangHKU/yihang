/****************************************************************************
 *
 *   Copyright (C) 2013-2016 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* Auto-generated by genmsg_cpp from file vehicle_local_position_setpoint.msg */


#include <cinttypes>
#include <px4_log.h>
#include <px4_defines.h>
#include <uORB/topics/vehicle_local_position_setpoint.h>
#include <drivers/drv_hrt.h>
#include <lib/drivers/device/Device.hpp>

constexpr char __orb_vehicle_local_position_setpoint_fields[] = "uint64_t timestamp;float x;float y;float z;float yaw;float yawspeed;float vx;float vy;float vz;float acc_x;float acc_y;float acc_z;float jerk_x;float jerk_y;float jerk_z;float[3] thrust;uint8_t[4] _padding0;";

ORB_DEFINE(vehicle_local_position_setpoint, struct vehicle_local_position_setpoint_s, 76, __orb_vehicle_local_position_setpoint_fields);
ORB_DEFINE(trajectory_setpoint, struct vehicle_local_position_setpoint_s, 76, __orb_vehicle_local_position_setpoint_fields);


void print_message(const vehicle_local_position_setpoint_s& message)
{
	PX4_INFO_RAW(" vehicle_local_position_setpoint_s\n");
	if (message.timestamp != 0) {
		PX4_INFO_RAW("\ttimestamp: %" PRIu64 "  (%.6f seconds ago)\n", message.timestamp, hrt_elapsed_time(&message.timestamp) / 1e6);
	} else {
		PX4_INFO_RAW("\n");
	}
	PX4_INFO_RAW("\tx: %.4f\n", (double)message.x);
	PX4_INFO_RAW("\ty: %.4f\n", (double)message.y);
	PX4_INFO_RAW("\tz: %.4f\n", (double)message.z);
	PX4_INFO_RAW("\tyaw: %.4f\n", (double)message.yaw);
	PX4_INFO_RAW("\tyawspeed: %.4f\n", (double)message.yawspeed);
	PX4_INFO_RAW("\tvx: %.4f\n", (double)message.vx);
	PX4_INFO_RAW("\tvy: %.4f\n", (double)message.vy);
	PX4_INFO_RAW("\tvz: %.4f\n", (double)message.vz);
	PX4_INFO_RAW("\tacc_x: %.4f\n", (double)message.acc_x);
	PX4_INFO_RAW("\tacc_y: %.4f\n", (double)message.acc_y);
	PX4_INFO_RAW("\tacc_z: %.4f\n", (double)message.acc_z);
	PX4_INFO_RAW("\tjerk_x: %.4f\n", (double)message.jerk_x);
	PX4_INFO_RAW("\tjerk_y: %.4f\n", (double)message.jerk_y);
	PX4_INFO_RAW("\tjerk_z: %.4f\n", (double)message.jerk_z);
	PX4_INFO_RAW("\tthrust: [%.4f, %.4f, %.4f]\n", (double)message.thrust[0], (double)message.thrust[1], (double)message.thrust[2]);
	
}
