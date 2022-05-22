type Person = {
  height: number;
  name: string;
  club: string;
  parents: string[];
  gol(): void;
};

const eu: Person = {
  height: 1.75,
  name: 'Tiago L.',
  club: 'Santa Cruz',
  parents: ['Mae', 'Pai'],
  gol() {
    if (this.club === 'Santa Cruz') {
      console.log('GOOOOOL');
    }
  }
};

console.log(eu);

eu.height = 1.76;

console.log(eu);

eu.gol();

const outro: Person = {
  height: 1.80,
  name: 'Arthur V.',
  club: 'Sport',
  parents: ['Mae', 'Pai'],
  gol() {
    if (this.club === 'Santa Cruz') {
      console.log('GOOOOOL');
    }
    else {
      console.log('ok...');
    }
  }
};

console.log(outro);

outro.gol();
