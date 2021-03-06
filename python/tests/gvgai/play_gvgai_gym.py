from timeit import default_timer as timer
import numpy as np
import gym

from griddly import GymWrapperFactory, gd

if __name__ == '__main__':
    wrapper = GymWrapperFactory()

    wrapper.build_gym_from_yaml("Sokoban_Manual", 'Single-Player/GVGAI/sokoban.yaml', player_observer_type=gd.ObserverType.SPRITE_2D, level=1)

    env = gym.make(f'GDY-Sokoban_Manual-v0')

    env.reset()

    start = timer()

    frames = 0

    fps_samples = []

    for s in range(1000):

        frames += 1
        obs, reward, done, info = env.step(env.action_space.sample())
        env.render()
        #env.render(observer='global')

        if frames % 1000 == 0:
            end = timer()
            fps = (frames / (end - start))
            fps_samples.append(fps)
            print(f'fps: {fps}')
            frames = 0
            start = timer()
    print(f'mean fps: {np.mean(fps_samples)}')