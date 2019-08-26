uint32_t effTimer;

void effectsTick()
{
  if (!dawnFlag)
  {
    if (ONflag && (millis() - effTimer >= ((currentMode < 5 || currentMode > 13) ? modes[currentMode].Speed : 50)))
    {
      effTimer = millis();
      switch (currentMode)
      {
        case 0:  sparklesRoutine();    break;
        case 1:  fireRoutine();        break;
        case 2:  rainbowVertical();    break;
        case 3:  rainbowHorizontal();  break;
        case 4:  colorsRoutine();      break;
        case 5:  madnessNoise();       break;
        case 6:  cloudNoise();         break;
        case 7:  lavaNoise();          break;
        case 8:  plasmaNoise();        break;
        case 9:  rainbowNoise();       break;
        case 10: rainbowStripeNoise(); break;
        case 11: zebraNoise();         break;
        case 12: forestNoise();        break;
        case 13: oceanNoise();         break;
        case 14: colorRoutine();       break;
        case 15: snowRoutine();        break;
        case 16: matrixRoutine();      break;
        case 17: lightersRoutine();    break;
        case 18: lightBalls();         break;
        case 19: whiteColor();         break;
        default:                       break;
      }
      FastLED.show();
    }
  }
}

void changePower()
{
  if (ONflag)
  {
    effectsTick();
    for (uint8_t i = 0; i < modes[currentMode].Brightness; i = constrain(i + 8, 0, modes[currentMode].Brightness))
    {
      FastLED.setBrightness(i);
      delay(1);
      FastLED.show();
    }
    FastLED.setBrightness(modes[currentMode].Brightness);
    delay(2);
    FastLED.show();
  }
  else
  {
    effectsTick();
    for (uint8_t i = modes[currentMode].Brightness; i > 0; i = constrain(i - 8, 0, modes[currentMode].Brightness))
    {
      FastLED.setBrightness(i);
      delay(1);
      FastLED.show();
    }
    FastLED.clear();
    delay(2);
    FastLED.show();
  }
  
  TimerManager::TimerRunning = false;
  TimerManager::TimerHasFired = false;
  TimerManager::TimeToFire = 0ULL;

  FavoritesManager::FavoritesRunning = false;
}
