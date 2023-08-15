export class Engine {
    private defaultWidth: number = 800;
    private defaultHeight: number = 600;
    private canvas?: HTMLCanvasElement;

    public get canvasId() { return "amethyst-canvas" }

    constructor(rootId?: string) {
        this.initCanvas(rootId);
        this.initContext();
    }

    private initContext = async () => {
        const adaptater = await navigator.gpu.requestAdapter();
        console.log(adaptater);
        const device = await adaptater?.requestDevice();
        console.log(device);
    }

    private initCanvas = (rootId?: string) => {
        const root = rootId ? document.getElementById(rootId) : document.body;
        this.canvas = document.createElement('canvas');
        this.canvas.id = this.canvasId;
        this.canvas.style.background = 'rgba(20, 20, 20, 10)';
        this.canvas.width = this.defaultWidth;
        this.canvas.height = this.defaultHeight;
        root?.appendChild(this.canvas);
    }
}