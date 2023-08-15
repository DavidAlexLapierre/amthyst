import { Engine } from '@amethyst/rendering';

export class Game {
    private title: string;
    private engine: Engine;

    constructor(title: string, rootId?: string) {
        this.title = title;
        this.engine = new Engine(rootId);
    }

    run() {
        console.log(this.title);
    }
}