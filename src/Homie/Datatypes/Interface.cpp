
    with State(lock=True) as data:
        if "settings" in data:
            del data['settings']


def get_session_var(name, default=None):
    return SESSION_VARS.get(name, default)


def set_session_var(name, value):
    assert name in SESSION_VARS
    SESSION_VARS[name] = value


def is_disabled_progressbar():
    return any([
        get_session_var("force_option"), util.is_ci(),
        getenv("PLATFORMIO_DISABLE_PROGRESSBAR") == "true"
    ])


def get_cid():
    cid = get_state_item("cid")
    if not cid:
        _uid = None
        if getenv("C9_UID"):
            _uid = getenv("C9_UID")
        elif getenv("CHE_API", getenv("