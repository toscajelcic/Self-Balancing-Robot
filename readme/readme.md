# Self-Balancing Robot

A two-wheeled self-balancing robot built with an Arduino Uno, using PID control 
to maintain upright balance based on real-time tilt data from an IMU.

## Components
- Arduino Uno
- MPU-6050 (6-axis accelerometer/gyroscope)
- TB6612FNG dual motor driver
- 2x JGA25-370 DC motors with encoders
- OLED display (I2C)
- 3D-printed chassis
- LiPo battery

## How It Works
1. The MPU6050 measures tilt angle via accelerometer + gyroscope fusion
2. A PID control loop calculates motor output needed to correct tilt
3. The TB6612FNG drives both motors to move the robot in the direction 
   needed to stay balanced
4. Motor encoders provide feedback on wheel speed/position
5. OLED displays live status/debug info

## Wiring

### MPU6050 → Arduino
| MPU6050 | Arduino |
|---------|---------|
| VCC     | 5V      |
| GND     | GND     |
| SCL     | A5      |
| SDA     | A4      |

### TB6612FNG → Arduino
| TB6612FNG | Arduino |
|-----------|---------|
| VM        | Battery+ |
| VCC       | 5V      |
| GND       | GND (common) |
| STBY      | 5V      |
| PWMA      | ~9      |
| AIN1      | 8       |
| AIN2      | 7       |
| PWMB      | ~10     |
| BIN1      | 6       |
| BIN2      | 5       |

## Project Status
- [x] MPU6050 wired and reading data
- [ ] Motor driver wired and tested
- [ ] PID balancing loop
- [ ] Frame designed/printed
- [ ] Full assembly

## Notes
- Used [Electronic Cats MPU6050 library] instead of Adafruit's — Adafruit's 
  strict chip-ID check rejected this particular sensor (likely an AliExpress 
  clone with a slightly different WHO_AM_I response), even though the sensor 
  itself works fine.
