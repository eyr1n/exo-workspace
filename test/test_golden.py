from pytest import Config

from exo_workspace import avx2_matmul


def test_golden(pytestconfig: Config):
    actual = str(avx2_matmul.rank_k_reduce_6x16) + "\n"
    expected = (pytestconfig.rootpath / "test" / "golden.txt").read_text()
    assert actual == expected


def test_golden_scheduled(pytestconfig: Config):
    actual = str(avx2_matmul.avx) + "\n"
    expected = (pytestconfig.rootpath / "test" / "golden_scheduled.txt").read_text()
    assert actual == expected
