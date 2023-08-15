import { CanvasManager } from "@amethyst/canvas";

export class Game {
    private title: string;
    private _canvasManager: CanvasManager;

    constructor(title: string, width: number, height: number, rootId?: string) {
        this.title = title;
        this._canvasManager = new CanvasManager();
        this._canvasManager.initCanvas(width, height, rootId);
    }

    run() {
        console.log(this.title);
    }
}