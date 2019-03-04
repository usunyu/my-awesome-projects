class PowerGrid {
  List<PowerPlant> connectedPlants = [];
  
  addPlant(PowerPlant plant) {
    bool confirm = plant.turnOn('5 hours');
    if (confirm)
        connectedPlants.add(plant);
  }
}

abstract class PowerPlant {
  int costOfEnegy;
  
  bool turnOn(String duration);
}

class NuclearPlant implements PowerPlant {
  int costOfEnegy;
  
  bool turnOn(String duration) {
    print('Im a nuclear plant turnning on.');
    return true;
  }
}

class SolarPlant implements PowerPlant {
  int costOfEnegy;
  
  bool turnOn(String duration) {
    print('Im a solar plant turnning on.');
    return true;
  }
}

void main() {
  PowerGrid grid = new PowerGrid();
  NuclearPlant nuclear = new NuclearPlant();
  SolarPlant solar = new SolarPlant();
  
  grid.addPlant(nuclear);
  grid.addPlant(solar);
}