// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include <frc/Encoder.h>
#include "RobotContainer.h"

#include "subsystems/Claw.h"
#include "subsystems/AlgaeInt.h"
#include "subsystems/Vertical.h"

#include <cameraserver/CameraServer.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;
AlgaeInt Algae;
  Claw ClawHand;
  Vertical Elevator;
  frc::Encoder testEncoder{0, 1, false, frc::Encoder::EncodingType::k2X};
  frc::XboxController Xbox{0};

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc2::Command* m_autonomousCommand = nullptr;
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  RobotContainer m_container;
};
