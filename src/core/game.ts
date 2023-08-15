export class Game {
    private title: string;

    constructor(title: string, width: number, height: number, rootId?: string) {
        this.title = title;
        this.initCanvas(width, height, rootId);
    }

    private initCanvas(width: number, height: number, rootId?: string) {
        const root = rootId ? document.getElementById(rootId) : document.body;
        const canvas = document.createElement('canvas');
        canvas.width = width;
        canvas.height = height;
        canvas.style.background = 'rgba(20, 20, 20, 1.0)';
        root?.appendChild(canvas);
    }

    run() {
        console.log(this.title);
    }
}